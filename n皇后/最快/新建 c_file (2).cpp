#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long sum = 0, upperlim = 1;

void test(long row, long ld, long rd) \\row��ʾ�Ѿ��лʺ���У�ld��rd�ֱ��ʾ�Ѿ��лʺ��б�У�ÿһλ��ʾ�����п��԰ڷŻʺ��λ�ã�1��ʾ���԰ڷţ�0��ʾ�����԰ڷš�row��ÿ������һ��ʱ���øĶ���ld��rd��Ҫ�ֱ����ƺ�����һλ��
{

   if (row != upperlim) \\�������ж��лʺ�ʱ˵���ڷ����
   {
  long pos = upperlim & ~(row | ld | rd); \\pos��ÿһλ��ʾ�����п��԰ڷŻʺ��λ�ã�1��ʾ���԰ڷţ�0��ʾ�����԰ڷ�
  while (pos) \\���pos�л��п��԰ڷŵ�λ��
  {
 long p = pos & -pos; \\pΪpos����ĩһ�����԰ڷŵ�λ��

 pos -= p; \\��p�ӿɰڷ�λ��ȥ��
 test(row + p, (ld + p) << 1, (rd + p) >> 1); \\����һ�н����ж�
  }
   } else
  sum++;
}

int main(int argc, char *argv[])
{
   time_t tm;
   int n = 16;

   if (argc != 1)
  n = atoi(argv[1]);
   tm = time(0);
   if ((n < 1) || (n > 32))
   {
  printf(" ֻ�ܼ���1-32֮��\n");
  exit(-1);
   }
   printf("%d �ʺ�\n", n);
   upperlim = (upperlim << n) - 1;

   test(0, 0, 0);
   printf("����%ld������, ����ʱ��%d�� \n", sum, (int) (time(0) - tm));
}