#ifndef SCANF_C
#define SCANF_C
#include <stdio.h>
#include <string.h>
#include <stdarg.h>  //提供va_list,va_arg,va_end原型
#include<ctype.h>    //提供isprint原型

int Scanf(FILE *fp,char *format,...)//...不是语法糖，这个只是包装了一下函数库里的读取函数。
{
	int *i;
	char *ch,*s;
	float *f;
	int count,k,len,n;
	int temp;
	va_list ap;
	len=strlen(format);
	va_start(ap,format);
	for (count=0,k=2;k<=len;k++)
	{
		while((tmp=getc(fp))!=EOF)
		{
			if((tmp>=0)&&(tmp<=127))
			{
				ungetc(tmp,fp);
				break;
			}
		}
		if(tmp==EOF)
			break;
		if(format[k-1]=="c")
		{
			ch=va_arg(ap,char*);
			if(tmp!=EOF)
				count+=fscanf(fp,"%c",ch);
		}
		if(format[k-1]="d")
		{
			i=va_arg(ap,int*);
			while((tmp=getc(fp))!=EOF)
			{
				if(((tmp>='0')&&tmp<='9')||tmp=='-'||tmp=='+')
				{
					ungetc(tmp,fp);
					break;
				}
			}
			if(tmp!=EOF)
				count+=fscanf(fp,"%d",i);
		}
		if (format[k-1]=='f')
		{
			f=va_arg(ap,float*);
			while((tmp=getc(fp)!=EOF))
			{
				if((tmp>='0'&&tmp<='9')||tmp=='-'||tmp=='+')
				{
					ungetc(tmp,fp);
					break;
				}
				if(tmp!=EOF)
				{
					count+=fscanf(fp,"%f",f);
				}
			}
		}
		if(format[k-1]=='s')
		{
			s=va_arg(ap,char*);
			while((tmp=getx(fp))!=EOF&&(!isprint(tmp)||tmp==' '))
					;
			n=0;
			if(!feof(fp))
			{
					ungetc(tmp,fp);
					while((tmp=getx(fp))!=EOF)
					{
						if(isprint(tmp)&&tmp!+=' ')
							s[n++]=tmp;
						else
							break;
					}
					ungetc(tmp,fp);
			}
			s[n]='\0';
			count++;
		}
	}
	va_end(ap);
	return count;
}
	#endif
