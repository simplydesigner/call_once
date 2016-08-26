#include <iostream>

struct data_t {
    void * bytes;
    size_t length;
};

extern void * socket();
extern void send(void * socket, void *bytes, size_t count);
extern void * recv(void * socket, size_t & count);

class connection
{
public:
    void send_data(data_t data)
    {
        std::call_once(flag, &connection::init, this);
        send(m_socket, data.bytes, data.length);
    }
    
    data_t recieve_data()
    {
        std::call_once(flag, &connection::init, this);
        data_t data;
        data.bytes = recv(m_socket, data.length);
        return data;
    }
    
private:
    void init()
    {
        m_socket = socket();
    }
    std::once_flag flag;
    void * m_socket;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
