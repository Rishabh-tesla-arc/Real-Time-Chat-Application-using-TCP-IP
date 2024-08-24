#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *receive_messages(void *sock) {
    int server_sock = *((int *)sock);
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        printf("%s\n", buffer);
    }

    return NULL;
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE];
    pthread_t tid;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server. You can start chatting now.\n");

    pthread_create(&tid, NULL, receive_messages, (void *)&sock);

    while (fgets(message, sizeof(message), stdin) != NULL) {
        send(sock, message, strlen(message), 0);
    }

    close(sock);
    return 0;
}
