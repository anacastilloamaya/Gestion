<<<<<<< HEAD
#include "../../edroomsl/include/edroomsl/edroomtc.h"

#include <stdio.h>


static bool opened = 0;
//static FILE *fp = NULL;

CEDROOMstream::CEDROOMstream()
{
    if(!opened)
    {
        /*  Init the RTEMS filesyste    */
    	printf("stream abierto(por pantalla...)\n");
        
        opened = 1;
    }
        
}

CEDROOMstream::CEDROOMstream(const char *string) 
{
    CEDROOMstream();
}

void CEDROOMstream::open(const char *string, int dummy)
{
    /*  NOTHING */
}

void CEDROOMstream::close(void) 
{
    /*  NOTHING */
}

void CEDROOMstream::reopen(void) 
{
    /*  NOTHING */
}

int CEDROOMstream::is_open(void) 
{
    return (opened);
}

int CEDROOMstream::good(void) 
{
    return (opened);
}
    
CEDROOMstream & CEDROOMstream::operator<<(const char *string) 
{
 //   fprintf(fp, string);
	printf("%s",string);
    return (*this);
}

CEDROOMstream & CEDROOMstream::operator<<(const int &integer) 
{
    
    printf("%i",integer);

    return (*this);
}

CEDROOMstream & CEDROOMstream::operator<<(const unsigned int &uint) 
{
    
	printf("%u",uint);

    return (*this);
}

CEDROOMstream & CEDROOMstream::operator<<(const float &fnum) 
{
	    return (*this);
}

=======
#include "../../edroomsl/include/edroomsl/edroomtc.h"

#include <stdio.h>


static bool opened = 0;
//static FILE *fp = NULL;

CEDROOMstream::CEDROOMstream()
{
    if(!opened)
    {
        /*  Init the RTEMS filesyste    */
    	printf("stream abierto(por pantalla...)\n");
        
        opened = 1;
    }
        
}

CEDROOMstream::CEDROOMstream(const char *string) 
{
    CEDROOMstream();
}

void CEDROOMstream::open(const char *string, int dummy)
{
    /*  NOTHING */
}

void CEDROOMstream::close(void) 
{
    /*  NOTHING */
}

void CEDROOMstream::reopen(void) 
{
    /*  NOTHING */
}

int CEDROOMstream::is_open(void) 
{
    return (opened);
}

int CEDROOMstream::good(void) 
{
    return (opened);
}
    
CEDROOMstream & CEDROOMstream::operator<<(const char *string) 
{
 //   fprintf(fp, string);
	printf("%s",string);
    return (*this);
}

CEDROOMstream & CEDROOMstream::operator<<(const int &integer) 
{
    
    printf("%i",integer);

    return (*this);
}

CEDROOMstream & CEDROOMstream::operator<<(const unsigned int &uint) 
{
    
	printf("%u",uint);

    return (*this);
}

CEDROOMstream & CEDROOMstream::operator<<(const float &fnum) 
{
	    return (*this);
}

>>>>>>> 6d9cb93b91611dc8887ee389468b7d9606c9212f
