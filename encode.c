#include <stdio.h>
#include <stdlib.h>
#include "test.pb-c.h"

enum {
        ADD_REQ = 1,
        MULT_REQ
};

int main (int argc, const char * argv[]) 
{
        DMessage        msg  = DMESSAGE__INIT;   // DMESSAGE
        Rpcheader     header = RPCHEADER__INIT; // SUBMESSAGE A
        char *buf;
        unsigned len;

        header.rpcreq = MULT_REQ; 
        msg.header = &header;               // Point msg.a to sub1 data

        msg.a = 10;
        msg.b = 20;

        len = dmessage__get_packed_size (&msg); // This is the calculated packing length
        buf = malloc (len+1);                     // Allocate memory
        buf[0]=len;
        dmessage__pack (&msg, &buf[1]);             // Pack msg, including submessages

        fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
        fwrite (buf,1, len+1, stdout);           // Write to stdout to allow direct command line piping

        free(buf); // Free the allocated serialized buffer
        return 0;
}

