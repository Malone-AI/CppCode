#include <stdio.h>
#include <stdlib.h>
typedef struct//操作数栈
{
	double *top;
	double *base;
	int listsize;
}List;
typedef struct//操作符栈
{
	char *top;
	char *base;
	int nodesize;
}Node;
int InitList(List *p)//初始化操作数栈
{
	p->base=(double *)malloc(100*sizeof(double));
	if(!p->base)
		return 0;
	p->top=p->base;
	p->listsize=100;
	return 1;
}
int PushList(List *p,double e)//操作数进栈
{
	if(p->top-p->base>=p->listsize)
	{
		p->base=realloc(p->base,(p->listsize+10)*sizeof(double));
		if(!p->base)
			return 0;
		p->top=p->base+p->listsize;
		p->listsize+=10;
	}
	*(p->top++)=e;
	return 1;
}
double PopList(List *p)//操作数出栈
{
	double e;
	if(p->base==p->top)
		return 0;
	else
		e=*(--p->top);
	return e;
}
double getTopList(List *p)//得到操作数栈的栈顶元素
{
	double e;
	if(p->base==p->top)
		return 0;
	e=*(p->top-1);
	return e;
}
void print(List *p)//打印操作数中的元素
{
	double *p1;
	if(p->base==p->top)
	{
		printf("数字空栈！！！！\n");
		exit(0);
	}
	p1=p->top;
	while(p1!=p->base)
	{
		printf("%.2lf\n",*(p1-1));
		p1--;
	}
}
void printNode(Node *p)//打印操作符中的元素
{
	char *p1;
	if(p->base==p->top)
	{
		printf("字符空栈！！！！\n");
		exit(0);
	}
	p1=p->top;
	while(p1!=p->base)
	{
		printf("%c\n\n",*(p1-1));
		p1--;
	}
}

int InitNode(Node *p)//初始化操作符栈
{
	p->base=(char *)malloc(100*sizeof(char));
	if(!p->base)
		return 0;
	p->top=p->base;
	p->nodesize=100;
	return 1;
}
int PushNode(Node *p,char e)//操作符进栈
{
	if(p->top-p->base>=p->nodesize)
	{
		p->base=realloc(p->base,(p->nodesize+10)*sizeof(char));
		if(!p->base)
			return 0;
		p->top=p->base+p->nodesize;
		p->nodesize+=10;
	}
	*(p->top++)=e;
	return 1;
}
char PopNode(Node *p)//操作符出栈
{
	char e;
	if(p->base==p->top)
		return 0;
	else
		e=*(--p->top);
	return e;
}
char getTopNode(Node *p)//得到操作符栈顶元素
{
	char e;
	if(p->base==p->top)
		exit(0);
	e=*(p->top-1);
	return e;
}
int Length(char *s)//求表达式的长度
{
	int i=0,b=0;
	while(*(s+i)!='\0')
	{
		b++;
		i++;
	}
	return b;
}
int empty(Node *p)//判断操作符栈是否为空
{
	if(p->base==p->top)
	{
		return 1;
	}
	else
		return 0;
	return 1;
}
int compare(char ch)//判断符号优先级
{
	if(ch=='(')return 1;
	else if(ch=='#') return 0;
	else if(ch=='+'||ch=='-')return 2;
	else if(ch=='*'||ch=='/')return 3;
	else return 4;
}
double add(double num2,char op,double num1)//实现四则运算
{
	double c;
	switch(op)
	{
		case '+':c=num2+num1;break;
		case '-':c=num2-num1;break;
		case '*':c=num2*num1;break;
		case '/':c=num2/(num1*1.0);break;
	}
	return c;
}
int isop(char c)//判断表达式是否符合四则运算
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='#')
		return 1;
	if(c=='('||c==')')
		return 2;
/*	else
		printf("表达式有误！！！\n");*/
	return 0;
}
double calculate()
{
	double a,result=0,x,y,b;//a储存进栈的操作数，result为计算结果，x和y是从操作数栈取出的两个栈顶元素
	int i=0,j=0,k=0;//i，j为循环变量
	char ch,s[100];//ch是操作符栈顶元素，s为表达式
	Node p1;//操作符栈
	List p2;//操作数栈
	InitList(&p2);
	InitNode(&p1);
	printf("输入表达式(输入'#'代表结束，不然可能会出错哟！):");
	gets(s);
	//printf("长度:%d\n",Length(s));
	while(s[i]!='\0'&&i<Length(s))
	{
		k=0;
		b=0;
		a=0;
		j=i;
		if(s[j]>='0'&&s[j]<='9')//若是操作数
		{
	
			while(s[j]>='0'&&s[j]<='9')       //将操作数（可能有多个连续的数字）转化为double型数据

			{
				a=(double)((s[j]-'0')+a*10);
				j++;
			}
			if(s[j]=='.')//如果存在小数
			{
				j++;
				if(s[j]>='0'&&s[j]<='9')//若是操作数
				{
	
					while(s[j]>='0'&&s[j]<='9')       //将操作数（可能有多个连续的数字）转化为double型数据
					{
						b=(double)((s[j]-'0')+b*10);
						k++;
						j++;
					}
					for(i=0;i<k;i++)
						b=b/(10.0);
					a=a+b;
				}
			}
				
			i=--j;
			PushList(&p2,a);
		}
		
		else if(isop(s[i])==1)//若是+，-，*，/
		{
			if(empty(&p1)) //操作符栈为空，直接进栈
				PushNode(&p1,s[i]);
			else//操作符栈不为空
			{
				while(!empty(&p1))
				{
					ch=getTopNode(&p1);//取栈顶操作符
					//printf("ch=%c\n",ch);
					if(compare(ch)>=compare(s[i]))//当前即将进栈的元素大于栈顶元素的优先级，则计算
					{
						x=PopList(&p2);
						y=PopList(&p2);
						result=add(y,ch,x);
					//	printf("结果:%.2lf\n",result);
						PopNode(&p1);
						PushList(&p2,result);
					}
					else break;
				}
				if(s[i]!='#')
				PushNode(&p1,s[i]);
			}
				//i++;
		}
		else if(isop(s[i])==2)//若有括号即将进栈
		{
			if(s[i]=='(')
				PushNode(&p1,s[i]);//左括号直接进栈
			else//若为右括号
			{
				while(getTopNode(&p1)!='(')//直到找到左括号，否则计算
				{
					ch=getTopNode(&p1);
					x=PopList(&p2);
					y=PopList(&p2);
					result=add(y,ch,x);
					PopNode(&p1);
					PushList(&p2,result);
				}
				PopNode(&p1);
			}
		}
		i++;
	}
	while(!empty(&p1))//若操作符栈不为空，则继续计算
	{
		ch=getTopNode(&p1);
		x=PopList(&p2);
		y=PopList(&p2);
		result=add(y,ch,x);
		PopNode(&p1);
		PushList(&p2,result);
	}
//	return getTopList(&p2);
//	print(&p2);
//	printNode(&p1);
	return getTopList(&p2);//返回操作数的栈顶元素（即为最终计算结果）
}

int main()
{
	printf("\n******************     计   算   器   ********************\n");
	printf("*********************  使 用 说 明  **********************\n");
	printf("*1：本计算器能运算'+''-''*''÷'以及括号运算四种基本运算\n");
	printf("*2：输入的括号必须是英文状态下的括号\n");
	printf("*3：输入的数字可以是多位数,也可以是小数\n");
	printf("*4：输入时以'#'作为结束\n");
	printf("********************************************************\n");
	printf("\n计算结果：result=%.2lf\n\n",calculate());
	return 0;
}

