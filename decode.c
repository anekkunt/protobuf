#include <stdio.h>
#include "test.pb-c.h"
#define MAX_MSG_SIZE 4096
enum {
        ADD_REQ=1,
        MULT_REQ
};

int main (int argc, const char * argv[]) 
{
        DMessage *msg;         // DMessage using submessages
        Rpcheader     *header ; // SUBMESSAGE A
        char len; int i=0;       // Data holders
        uint8_t buf[MAX_MSG_SIZE]; // Input data container for bytes

        fread(&len,1,1,stdin);
        printf("\npayload len=%d\n",len);
        fread(buf,1,len,stdin) ;

        msg = dmessage__unpack(NULL,len,buf); // Deserialize the serialized input
        if (msg == NULL)
        { // Something failed
                fprintf(stderr,"error unpacking incoming message\n");
                return 1;
        }
        header = msg->header;

        switch(header->rpcreq)
        {
                case ADD_REQ :
                        printf("\n%d+%d=%d\n",msg->a, msg->b, msg->a + msg->b );
                        break;
                case MULT_REQ:
                        printf("\n%d*%d=%d\n",msg->a, msg->b,msg->a * msg->b );
                        break;

        }

        dmessage__free_unpacked(msg,NULL);

        return 0;
}
