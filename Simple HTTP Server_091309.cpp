#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

class SimpleHttpsServer {
	private:
		int server_fd;
		
	public:
		SimpleHttpServer(int port) {
			server_fd = socket(AF_INET, SOCK_STREAM, 0);
			struct sockaddr_in address{};
			address.sin_family = AF_INET;
			address.sin_addr.s_s_addr = INADDR_ANY;
			address.sin_port = htons(port);
			
			bind(server_fd, (struct sockaddr*)&address, sizeof(address));
			listen(server_fd, 3);
			
			std::cout << "Server listening on port" << port std::endl;
		}
		
		void serve() {
			while (true) {
				int client_fd = accept(servre_fd, nullptr, nullptr);
				char buffer[1024] = [0];
				read(client_fd, buffer, sizeof(buffer));
				
				std::string response = "HTTp/1.1 200 OK\nContent-Length: 13\n\nHello World!";
				send(client_fd, response.c_str(), response.size(), 0);
			}
		}
		
		~SimpleHttpServer () {
			close(server_fd);
		}
};

int main() {
	SimpleHttpServer server(8080);
	server.serve();
	
	return 0;
}