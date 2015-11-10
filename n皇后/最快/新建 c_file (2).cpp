#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long sum = 0, upperlim = 1;

void test(long row, long ld, long rd) \\row表示已经有皇后的行，ld、rd分别表示已经有皇后的斜列，每一位表示该列中可以摆放皇后的位置，1表示可以摆放，0表示不可以摆放。row在每查找下一列时不用改动，ld、rd需要分别左移和右移一位。
{

   if (row != upperlim) \\当所有行都有皇后时说明摆放完毕
   {
  long pos = upperlim & ~(row | ld | rd); \\pos的每一位表示该列中可以摆放皇后的位置，1表示可以摆放，0表示不可以摆放
  while (pos) \\如果pos中还有可以摆放的位置
  {
 long p = pos & -pos; \\p为pos中最末一个可以摆放的位置

 pos -= p; \\将p从可摆放位置去掉
 test(row + p, (ld + p) << 1, (rd + p) >> 1); \\对下一列进行判断
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
  printf(" 只能计算1-32之间\n");
  exit(-1);
   }
   printf("%d 皇后\n", n);
   upperlim = (upperlim << n) - 1;

   test(0, 0, 0);
   printf("共有%ld种排列, 计算时间%d秒 \n", sum, (int) (time(0) - tm));
}