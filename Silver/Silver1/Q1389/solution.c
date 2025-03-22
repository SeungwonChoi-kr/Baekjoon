/* 케빈 베이컨의 6단계 법칙 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 101
#define bigger(x, y) ((x) > (y) ? (x) : (y))
#define smaller(x, y) ((x) < (y) ? (x) : (y))

typedef struct Node {
    int vertex_num;
    int weigh;
    struct Node* link;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    int size;
} Queue;

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_queue[MAX_VERTICES];
} GraphType;

void init_queue(Queue* l);
void insert_queue(Queue* l, int u, int weigh);
Node* pop_queue(Queue* l);
void init_graph(GraphType* g, int N);
void insert_edge(GraphType* g, int u, int v);
int bfs(GraphType* g, int u, bool* visited, int* min_way, int cur_d, Queue* queue);
void check(GraphType* g);

int main() {
    int N, M, u, v;
    scanf("%d %d", &N, &M);

    GraphType* graph = (GraphType*)malloc(sizeof(GraphType));
    init_graph(graph, N);
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        insert_edge(graph, u, v);
        insert_edge(graph, v, u);
    }
    // check(graph);

    bool* visited = (bool*)malloc((N + 1) * sizeof(bool));
    int* min_way = (int*)malloc((N + 1) * sizeof(int));
    int cur_d = 1;
    int vertex_kevin_bakers = 0;
    int smallest = -1;       // 각 정점들의 최소값을 저장하기 위해 -1을 초기값으로 -> 첫 노드가 무조건 최소값으로
    int that_vertex_num = 1; // 그리고 그 최소값에 해당하는 정점은 1이므로 1을 저장
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[j] = false;
            min_way[j] = 0;
        }

        init_queue(queue);
        vertex_kevin_bakers = bfs(graph, i, visited, min_way, cur_d, queue);

        // 1회용
        if (smallest == -1) {
            smallest = vertex_kevin_bakers;
        }

        if (smallest > vertex_kevin_bakers) {
            smallest = vertex_kevin_bakers;
            that_vertex_num = i;
        }
    }
    printf("%d", that_vertex_num);

    return 0;
}

void init_queue(Queue* l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void insert_queue(Queue* l, int u, int weigh) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex_num = u;
    node->weigh = weigh;

    if (l->size == 0) {
        l->head = node;
        l->tail = node;
        l->size++;
    } else {
        l->tail->link = node;
        l->tail = node;
        l->size++;
    }
}

Node* pop_queue(Queue* l) {
    if (l->size == 0) {
        return NULL;
    }

    Node* node;
    node = l->head;
    l->head = l->head->link;
    l->size--;

    return node;
}

void init_graph(GraphType* g, int N) {
    g->n = N;
    for (int i = 1; i <= N; i++) {
        g->adj_queue[i] = NULL;
    }
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_queue[u];
    g->adj_queue[u] = node;
}

int bfs(GraphType* g, int u, bool* visited, int* min_way, int cur_d, Queue* queue) {
    int cnt = 0;
    GraphNode* node;
    if (g->adj_queue[u] == NULL) {
        return cnt;
    }

    node = g->adj_queue[u]; // u 노드의 친구들을 찾기 위해 u 노드의 첫번째 친구를 node에 저장
    visited[u] = true;
    min_way[u] = 0;
    while (node) {
        if (visited[node->vertex]) { // 그 친구를 이미 확인했으면
            node = node->link;       // 그 다음 친구를 확인하기 위해 node를 다음 녀석으로 변경
            continue;
        }
        visited[node->vertex] = true;      // 확인 안 한 친구면 확인한 걸로 치고
        min_way[node->vertex] = cur_d;     // 현재 징검다리 수를 저장한 후
        insert_queue(queue, node->vertex, cur_d); // bfs를 하기 위해 큐에 저장하고
        cnt += cur_d;
        node = node->link; // 다음 친구를 확인
    }

    while (1) {
        if (queue->size == 0) { // pop_queue가 NULL일 경우 원천 차단
            break;
        } else {
            Node* node = pop_queue(queue);
            cnt += bfs(g, node->vertex_num, visited, min_way, node->weigh + 1, queue);
        }
    }

    return cnt;
}

void check(GraphType* g) {
    GraphNode* node;
    for (int i = 1; i <= g->n; i++) {
        printf("%d: ", i);
        node = g->adj_queue[i];
        while (node) {
            printf("%d ", node->vertex);
            node = node->link;
        }
        printf("\n");
    }
}