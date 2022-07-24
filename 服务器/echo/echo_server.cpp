#include <stdio.h>
#include <unisted.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERVER_PORT 666
prerror_exit(const* des) {
	fprint(stderr, "%s error,reason %s\n",des, strerror(errno));
	exit(1);
}


int main(void) {
	
	int sock,ret;
	struct sockaddr_in server_addr;
	//��������
	sock = socket(AF_INET, SOCK_STREAM, 0);

	//����ֱ�ӵ���֮ǰ�ı�����
	if (sock == -1) {
		fprint(stderr, "create socket error,reason %s\n", strerror(errno));
		exit(1);
	}
	//��ձ�ǩ��д�ϵ�ַ�Ͷ˿ں�
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET; //ѡ��Э������IPV4
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//������������ip��ַ
	server_addr.sin_port = htons(SERVER_PORT);//�󶨶˿ں�
	
	//ʵ�ַ�������ǩ����������
	ret = bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (ret == -1) {
		fprint(stderr, "bind error,reason %s\n", strerror(errno));
		close(sock); //��д�ɲ�д
		exit(1);
	}

	//�������64��
	ret = listen(sock, 64);
	if (ret == -1) {
		fprint(stderr, "listen error,reason %s\n", strerror(errno));
		close(sock);
		exit(1);
	}

	//������
	printf("�ȴ��ͻ��˵�����\n");

	int done = 1;
	while (done) {
		struct sockaddr_in client;
		int client_sock,len;
		char client_ip[64];
		char buf[256]

		socklen_t client_addr_len;
		client_addr_len = sizeof(client);
		client_sock = accept(sock, (struct sockaddr*)&client, &client_addr_len);
		//��ӡ�ͻ��˵�ַ��IP��
		print("client ip:%s\t port:%d\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)),
			ntohs(client.sin_port));
		//��ȡ�ͻ��˵�����
		len = read(client_sock, buf, sizeof(buf)-1);
		buf[len] = '\0';
		printf("recive:%s\n", len, buf);
		
		//ת���ɴ�д
		for (int i = 0; i < len; i++) {
			if (buf[i] >= 'a' && buf[i] <= 'z') {
				buf[i] = buf[i] - 32;
			}
		}
		len = write(client_sock, buf, len);

		printf("write finished. len : %d\n", len);
		close(client_sock);
	}  
	return 0;
}
