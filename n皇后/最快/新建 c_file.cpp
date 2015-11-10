#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long sum = 0, upperlim = 1;      // sum������¼����������upperlim������bit mark��
                              // �ж��ٸ��ʺ󣬾��ж���bit����1�����ӵ�λ����λ��

// ����˳���Ǵ��ұ��п�ʼ�ġ�
void test(long row, long ld, long rd) // row��¼���еķ�����Ϣ��bitΪ1ʱ�����Ѿ������˻ʺ�
// ld��¼����һ���ʺ�����1�в��ܷ��ûʺ�
//rd��¼�����1�в��ܷ��ûʺ�
// �磺��һ�ηŵ��ǵ�6��: ��
// row  ****  ****  **1*  ****
// ld   ****  ****  *1**  *****
// rd   ****  ****  ***1  ****
{
   if (row != upperlim)
   {
  long pos = upperlim & ~(row | ld | rd); // ��row��ld��rdͬʱΪ0��bit�������
  while (pos) // if pos = 0����ô�ʺ�û�еط��ţ�����
  {
 long p = pos & -pos; // ��pos����͵�Ϊ1��bit�⣬���е�λ�����ֵ��p
                           // pos���ı䡣��ȡ�ÿ��ԷŻʺ�����ұߵ��У�

 pos -= p;  // ��pos����͵�Ϊ1��bit���㡣�����ұߵ��У�Ϊѭ����׼����
 test(row + p, (ld + p) << 1, (rd + p) >> 1); // row + p����ǰ����1����ʾ�����˻ʺ�
                                             // (ld + p) << 1����������в��ܷš�
  }
   } else  // row��ÿһλΪ1�������лʺ󶼷ź��ˡ�
  sum++;
}

int main(int argc, char *argv[])
{
   time_t tm;
   int n = 16;

   if (argc != 1)
  n = atoi(argv[1]);
   tm = time(0);
   if ((n < 1) || (n > 32))      // longΪ32λ���Ǻǣ�����������<=32
   {
  printf(" ֻ�ܼ���1-32֮��\n");
  exit(-1);
   }
   printf("%d �ʺ�\n", n);
   upperlim = (upperlim << n) - 1;  //�ж��ٸ��ʺ󣬾��ж���bit����1�����ӵ�λ����λ��

   test(0, 0, 0);
   printf("����%ld������, ����ʱ��%d�� \n", sum, (int) (time(0) - tm));
}