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
	//创建信箱
	sock = socket(AF_INET, SOCK_STREAM, 0);

	//可以直接调用之前的报错方法
	if (sock == -1) {
		fprint(stderr, "create socket error,reason %s\n", strerror(errno));
		exit(1);
	}
	//清空标签，写上地址和端口号
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET; //选择协议中族IPV4
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//监听本地所有ip地址
	server_addr.sin_port = htons(SERVER_PORT);//绑定端口号
	
	//实现服务器标签贴到信箱上
	ret = bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (ret == -1) {
		fprint(stderr, "bind error,reason %s\n", strerror(errno));
		close(sock); //可写可不写
		exit(1);
	}

	//传输最多64个
	ret = listen(sock, 64);
	if (ret == -1) {
		fprint(stderr, "listen error,reason %s\n", strerror(errno));
		close(sock);
		exit(1);
	}

	//等来信
	printf("等待客户端的链接\n");

	int done = 1;
	while (done) {
		struct sockaddr_in client;
		int client_sock,len;
		char client_ip[64];
		char buf[256]

		socklen_t client_addr_len;
		client_addr_len = sizeof(client);
		client_sock = accept(sock, (struct sockaddr*)&client, &client_addr_len);
		//打印客户端地址和IP号
		print("client ip:%s\t port:%d\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)),
			ntohs(client.sin_port));
		//读取客户端的数据
		len = read(client_sock, buf, sizeof(buf)-1);
		buf[len] = '\0';
		printf("recive:%s\n", len, buf);
		
		//转换成大写
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
