#include "udp.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

namespace
{

class server : public net::connection
{
public:
    server(int sock, std::unique_ptr<::sockaddr_in> addr);
    ~server();

    std::variant<std::string, net::error> receive() const override;

private:
    int _sock;
    std::unique_ptr<::sockaddr_in> _addr;
};

server::server(int sock, std::unique_ptr<::sockaddr_in> addr)
    : _sock{sock},
      _addr{std::move(addr)}
{
}

server::~server()
{
    ::close(_sock);
}

std::variant<std::string, net::error> server::receive() const
{
    std::array<char, 1024> buf{};
    auto const recv_len = ::recvfrom(_sock, buf.data(), buf.size(), 0, nullptr, nullptr);
    if (recv_len < 0)
    {
        return net::error{};
    }

    return std::string{buf.begin(), buf.begin() + recv_len};
}

} // namespace

namespace net
{

std::unique_ptr<connection> udp_server(std::uint16_t port)
{
    auto const sock = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
    {
        return {};
    }

    auto addr = std::make_unique<::sockaddr_in>();

    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = htonl(INADDR_ANY);

    if (::bind(sock, reinterpret_cast<::sockaddr *>(addr.get()), sizeof(::sockaddr_in)) < 0)
    {
        ::close(sock);
        return {};
    }

    return std::make_unique<server>(sock, std::move(addr));
}

} // namespace net

/*
    struct timeval tv;
    tv.tv_sec = timeout_in_seconds;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
*/

/*
    // client//

	struct sockaddr_in si_other;
	int s, i, slen=sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];

	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die(&quot;socket&quot;);
	}

	memset((char *) &amp;si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	
	if (inet_aton(SERVER , &amp;si_other.sin_addr) == 0) 
	{
		fprintf(stderr, &quot;inet_aton() failed\n&quot;);
		exit(1);
	}

	while(1)
	{
		printf(&quot;Enter message : &quot;);
		gets(message);
		
		//send the message
		if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &amp;si_other, slen)==-1)
		{
			die(&quot;sendto()&quot;);
		}
		
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf,'&#92;&#48;', BUFLEN);
		//try to receive some data, this is a blocking call
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &amp;si_other, &amp;slen) == -1)
		{
			die(&quot;recvfrom()&quot;);
		}
		
		puts(buf);
	}

	close(s);
	return 0;
*/