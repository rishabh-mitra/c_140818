int buf[10];
buf[12] = 1;
void updateEnv ( char * str )
{
char * tmp ;
//int buf[10];
//buf[12] = 1;
tmp = getenv (" MYENV ") ;
if ( tmp != NULL )
strcpy ( str , tmp );  }
