#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 1001
#define COL 1001

int matrix[ROW][COL];
int visited[ROW] = {0};

int stack_top = -1;
int stack_size = ROW;
int stack[ROW];

int front = 0;
int rear = 0;
int queue[ROW];

int size_stack() {
  if (stack_top < 0)
    return 0;
  else
    return stack_top + 1;
}

int empty_stack() {
  if (stack_top == -1)
    return 1;
  else
    return 0;
}

int full_stack() {
  if (stack_top == stack_size - 1)
    return 1;
  else
    return 0;
}

void push_stack(int item) {
  if (full_stack()) {
    return;
  } else {
    *(stack + ++stack_top) = item;
  }
}

int pop_stack() {
  if (empty_stack()) {
    return 0;
  } else {
    return *(stack + stack_top--);
  }
}

int top_stack() {
  if (empty_stack()) {
    return 0;
  } else {
    return *(stack + stack_top);
  }
}

void dfs(int start, int max) {
  int i = 0, cur = 0;

  push_stack(start);
  while (!empty_stack()) {
    cur = top_stack();
    pop_stack();
    if (!visited[cur]) {
      visited[cur] = 1;
      printf("%d ", cur);

      for (i = max; i >= 1; i--) {
        if (matrix[cur][i] == 1 && !visited[i]) push_stack(i);
      }
    }
  }
}

int empty_queue() {
  if (front == rear) {
    return 1;
  } else
    return 0;
}

int full_queue() {
  if (((rear + 1) % ROW) == front) {
    return 1;
  } else
    return 0;
}

void push_queue(int item) {
  if (full_queue())
    return;
  else {
    rear = (rear + 1) % ROW;
    queue[rear] = item;
  }
}

int pop_queue() {
  if (empty_queue()) {
    return -1;
  } else {
    front = (front + 1) % ROW;
    return queue[front];
  }
}

int front_queue() {
  if (empty_queue()) {
    return -1;
  }

  else
    return queue[(front + 1) % ROW];
}

void bfs(int start, int max) {
  int i = 0, cur = 0;

  push_queue(start);
  while (!empty_queue()) {
    cur = front_queue();
    pop_queue();
    if (!visited[cur]) {
      visited[cur] = 1;
      printf("%d ", cur);

      for (i = 1; i <= max; i++) {
        if (matrix[cur][i] == 1 && !visited[i]) push_queue(i);
      }
    }
  }
}

int main(void) {
  int i, N, M, V, first, second;
  int j = 0;

  scanf("%d", &N);
  rewind(stdin);
  scanf("%d", &M);
  rewind(stdin);
  scanf("%d", &V);
  rewind(stdin);

  for (i = 0; i < M; i++) {
    scanf("%d", &first);
    rewind(stdin);
    scanf("%d", &second);
    rewind(stdin);
    matrix[first][second] = 1;
    matrix[second][first] = 1;
  }

  dfs(V, N);
  for (i = 0; i < ROW; i++) visited[i] = 0;
  // memset(visited, 0, sizeof(visited));
  printf("\n");
  bfs(V, N);
}