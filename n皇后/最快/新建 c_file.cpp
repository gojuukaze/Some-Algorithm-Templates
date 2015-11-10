#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long sum = 0, upperlim = 1;      // sum用来记录排列总数，upperlim用来作bit mark。
                              // 有多少个皇后，就有多少bit被置1。（从低位到高位）

// 放置顺序是从右边列开始的。
void test(long row, long ld, long rd) // row记录了列的放置信息。bit为1时代表已经放置了皇后。
// ld记录了上一个皇后的左边1列不能放置皇后。
//rd记录了左边1列不能放置皇后。
// 如：上一次放的是第6列: 则
// row  ****  ****  **1*  ****
// ld   ****  ****  *1**  *****
// rd   ****  ****  ***1  ****
{
   if (row != upperlim)
   {
  long pos = upperlim & ~(row | ld | rd); // 将row，ld，rd同时为0的bit提出来。
  while (pos) // if pos = 0，那么皇后没有地方放？？？
  {
 long p = pos & -pos; // 将pos除最低的为1的bit外，所有的位清零后赋值给p
                           // pos不改变。（取得可以放皇后的最右边的列）

 pos -= p;  // 将pos的最低的为1的bit清零。（次右边的列，为循环做准备）
 test(row + p, (ld + p) << 1, (rd + p) >> 1); // row + p将当前列置1，表示放上了皇后
                                             // (ld + p) << 1。设置左边列不能放。
  }
   } else  // row的每一位为1，即所有皇后都放好了。
  sum++;
}

int main(int argc, char *argv[])
{
   time_t tm;
   int n = 16;

   if (argc != 1)
  n = atoi(argv[1]);
   tm = time(0);
   if ((n < 1) || (n > 32))      // long为32位，呵呵，所以这里是<=32
   {
  printf(" 只能计算1-32之间\n");
  exit(-1);
   }
   printf("%d 皇后\n", n);
   upperlim = (upperlim << n) - 1;  //有多少个皇后，就有多少bit被置1。（从低位到高位）

   test(0, 0, 0);
   printf("共有%ld种排列, 计算时间%d秒 \n", sum, (int) (time(0) - tm));
}