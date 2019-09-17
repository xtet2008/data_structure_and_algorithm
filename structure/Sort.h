#include<stdio.h>
#include<stdlib.h>

//排序 {四类排序：插入，交换，选择，归并}
#define length 20

typedef int key;
typedef struct
{
    int key;
    // other items
}RecordType; //记录类型
typedef RecordType List[length+1];

//交换A和B元素，因为排序过程中多次用到，省得每次 temp变量啥的，所以干脆就单独抽象出来，提高效率
void Swap(List R, int A, int B){
    RecordType temp = R[A];
    R[A] = R[B];
    R[B] = temp;
}

//打印数组结果，方便观察每轮排序后的变化
void PrintList(List R){
    for(int i = 1; i<=length; i++){ 
        if(R[i].key != NULL){
            printf("  %d", R[i].key);
        }
    }
}



/*直接插入排序，
分类: 插入
稳定排序
time complex: O(n^2)
space complex: O(1)
思路：从第2个元素i开始，每次依次与左边所有的元素对比，如果左边的某个元素j大于i，
    就将左边那个较大的元素j往右偏移一位到j+1的位置(即：arr[j+1] = arr[j])，并同时将j-- (与下一个左边的元素对比 )
    到最后用  arr[j+1] = arr[i] （将i插入到 >i-- and <i++合适的位置，保证从左到右依次是升序）
技巧：可用arr[0]作为岗哨槽，每次保存着待插入的 arry[i]元素，
    一来保存了 i对应的值，不会因记录移动导致值丢失，
    二来减少了判断子遍历是否到底语句带来的时间消耗
*/
void straight_insert_sort(List R, int n)
{
    int i,j;

    printf("\nraw data: ");
    PrintList(R);

    for(i=2; i<=n; i++){ //从第二个记录起进行插入
        printf("\n插入第%d个元素[%d]: ", i, R[i].key);
        R[0] = R[i]; //将第i个记录设置为岗哨
        j=i-1;
        while(R[0].key < R[j].key) //与岗哨比较，直至键值不大于岗哨键值
        {
            R[j+1] = R[j]; //将第j个记录赋值给第 j+2个记录
            j--;
        }
        R[j+1] = R[0]; //将第i个记录插入到序列中
        PrintList(R);
    }
}



/*冒泡排序
分类: 交换
稳定排序
time complex: O(n^2)
space complex: O(1)
特点：如果序列是有序的(或者大部分是有序的)，那么用这种排序是效率最高的，因为有个 endsort用来记录每轮是否有交换过记录，如果没有则说明是有序，退出
思路：外循环i从第1个元素到最后倒数第二个元素n-1(因为到最后一轮已经排好序了，没必要再排了)
     内循环j从第1个元素到 n-i (要减掉外循环的元素i，因为那是已经过泡的元素，没必要再检查)
     核心地方：用内循环的元素 j与其右边的 j+1元素对比，如果左边 j> 右边j+1，则交换(以保证升序排列)，
            一轮循环过后，就能将j通过不断交换移到右边最顶位置
*/
void bubble_sort(List R, int n)
{
    printf("\nraw data: ");
    PrintList(R);

    int i,j,endsort;
    for(i=1; i<=n-1; i++){
        endsort = 0; //用来检查是否有交换过记录
        
        for(j=1; j<=n-i; j++){
            if(R[j].key > R[j+1].key){ //若逆序则交换记录(以保持升序)
                Swap(R, j, j+1);
                endsort = 1;
            }
        }
        printf("\n冒出第%d轮最大值:%d ", i, R[j]);
        PrintList(R);

        if(endsort == 0){
            break; //如果一轮下来还没有交换过任何记录，则说明已经是有序的，那没必要再排序了，直接中断
        } 
    }
}


/*快速排序
分类: 交换
不稳定排序
time complex: Avergae=O(nLog2n)，worst=O(n^2) if it is the sequence array
space complex: O(1)
特点：对于有序序列千万别选这种排序方法，不然就悲催了，找基值时需要挨个元素对比到底，会用到最差的时间复杂度
     平均时间性能最佳，对于大规模n的数据排序效果较好，对于较小的数据量n该算法效果不明显
思路：首先利用一个额外的函数 quick_partition进行交换排序，使整个大序列分成三部分， low区间 < R[x] < high区间
     上面low区间的所有元素都比 x 值小，high区间所有元素都比大
     然后分别递归排序左子序列 quick_sort(R, low, x-1)和右子序列 quick_sort(R, x+1, high)
     核心地方：利用 quick_partition将大块序列，划分两大子序列，和一个基元素x
*/
void quick_sort(List R, int low, int high)
{
    if(low<high){
        //首先进行一次粗糙的交换排序，把整个序列分成三部分， temp--, temp, temp++ ，满足 temp--的元素值 < temp < temp++值，并且返回R最后所在的位置
        int temp = quick_partition(R, low, high);
        printf("\n基值%d，快速交换到了位置%d: ", R[temp].key, temp);
        PrintList(R);
        quick_sort(R, low, temp-1); //对R左边temp--部分进行递归排序
        quick_sort(R, temp+1, high); //对R右边temp++部分进行递归排序
    }
}

//对R[low]，R[low+1]，...，R[high]子序列进行一趟快速排序，并返回基值x在排完序后所在的中间索引位置
int quick_partition(List R, int low, int high)
{
    RecordType x = R[low]; //置初值
    while(low < high)
    {
        while (low<high && R[high].key >= x.key){ //从右边开始找出第1个比基值x小的元素，(如果是>=基值，没找到，就右边一直--)
            high--;
        }//循环过后相当于 high 位置所在的元素值 < x
        R[low] = R[high]; //从右边把比x小的元素移到左边最低端

        while(low<high && R[low].key <= x.key){ // 从左边开始找第1个比基值x大的元素
            low++;
        }//循环过后相当于从左边找到了第1个比x大的元素
        R[high] = R[low]; //从左边把比x大的元素移至右边最顶端
    }// 循环过后，相当于从右区间里比x小的元素都往左边移了，从左区间里比x大的元素都往右移了
    R[low] = x; //最后一次移位一定是从左区间把比x大的那个元素，移向了右区间，所以需要把基值x补到左边这个空的位置

    return low; // low值，即是第一个基值元素x在整个序列中应该在的合适位置（满足左边元素比较其小，右边元素比其大）
}



/*直接选择排序， (依次选出最小，次小，次次小等元素和左1，左2，左3等交换，以保证从左到右递增序列)
分类: 选择
不稳定排序
time complex: O(n^2)
space complex: O(1)
思路：从第1个元素i开始外循环，将假设取 min =i 当前循环最小比较值，内循环j从i+1至n遍历，
    依次与之前的min比较，如果发现比min更小的元素，则min保存着最新最小的元素编号
    内轮循一轮过后再判断 min 与开始的 i对比是否相同，如果不同说说明发现更小的值了，用 swap函数交换min和i所对应的元素(保证从左到右递增排列)
*/
void select_sort(List R, int n)
{
    printf("\nraw data: ");
    PrintList(R);

    int min, i, j;
    for(i=1; i<=n-1; i++){
        min=i; //每次循环选择一个最小值
        for(j=i+1; j<=n; j++){
            if(R[j].key <R[min].key){
                min = j; // min永远保存着键值较小的记录下标
            }
        }
        printf("\n选择第%d轮最小值%d: ", i, R[min]);

        if (min != i){
            Swap(R, min, i); // 将最小键值交换至i个元素处，以保证从左从右是递增排序
        }
        PrintList(R);        
    }
}




/*堆排序
最小堆：{13, 40, 27, 88, 55, 34, 65, 92}，K<=2K and K<=2k+1 (k为索引号)
                        13
                       /   \
                     40      27
                    / \      /  \
                   88  55   34   65
                   /
                  92

最大堆：{92, 65, 88, 40, 55, 34, 13, 27}，K>=2k and K>=2k+1
                        92
                       /   \
                     65      88
                    / \      /  \
                   40  55   34   13
                   /
                  27
分类: 选择
不稳定排序
time complex: O(n Log2n)
space complex: O(1)
特点：无论是平均还是最坏的情况下，时间复杂度都是最低的，排序效率都是最高的
思路：1、先循环把所有非终端节点(从n/2 - 1)为根节点，n为最后一个节点，为参数建行建堆函数，这样使整个数组满足堆的特性（但并不完全是递增或递减）
     2、整个数组建完堆后，其堆顶值（左边第一个元素）必定是整个数组中最小（或最大）的值，然后将其和底端元素交换，这样最底端元素（最右边元素）的值最小
     3、再重新对左边区间建堆，选出次小的值放到堆顶，并重复第2步骤（对第2、3步骤进行n-1 层循环，即选出了倒数第二小的元素交换到合适位置，整个排序完成）
*/
void heap_sort(List R, int n)
/*对R[n]进行排序，排序完成后，R中记录按关键字降序排列（因为按最大堆的算法排，根元素最大，依次变小，最后一个元素最小
每次从上至下，把最小的元素往下沉）
*/
{
    printf("\nraw data: ");
    PrintList(R);

    int i;
    for(i=n/2; i>=1; i--){
        /*
        完全二叉树最后一个非终端结点是第 K=|n/2| 个元素，对于>K的终端节点因为没有孩子结点，只有一个根的子树已经是堆，不需要再建堆了。
        只需要根据 K--的包有含孩子终端节点建堆即可
        */
        int temp=R[i].key;
        sift(R, i, n); //从第n/2个记录开始进行筛选建堆
        printf("\n以上面第%d个非终端结点, %d为根建完堆: ", i, temp);
        PrintList(R);
    }//for循环对n/2所有非终端节点建完堆后，数组已满足最小堆的特性 (但还不是完全的升序排列)，最后一轮建堆后，第1个元素必定是整个数组最小的元素

    printf("\n");

    for(i=n; i>=2; i--){
        //将堆顶记录和堆中最后一个记录互换，因为堆顶的第一个元素是最小的元素，换到最后一个位置去
        int temp=R[1].key;
        Swap(R, 1, i); 
        printf("\n以上面堆顶(左边)最小元素%d, 交换至第%d个槽后，对左区间重建堆选出下一个最小元素放堆顶: ", temp, i);
    
        //调整R[1]，使R[1]，... , R[i-1] 变成堆，换完后再拿左边区间的所有元素建堆，选出次小的元素，然后循环上面的交换到后面次小位置去
        sift(R, 1, i-1); 
        
        PrintList(R);
    }
}

//建堆，所谓建堆的意思就是交换根和其孩子结点的值，使其满足根值 < 其任一孩子的值即可满足堆的特性（最大堆）
void sift(List R, int k, int m)
/*假设 R[k], R[k+1], ..., R[m]是以 R[k]为根的完全二叉树，R[k]的左、右子树均满足堆的性质。
本算法调整R[k]使整个序列R[k], R[k+1], ..., R[m]满足堆的性质
*/
{
    int i, j, x;
    RecordType t;
    i =k; //i代表根index
    j = 2*i; // j代表左子树index
    x = R[k].key; //x代表树根的值
    t=R[k]; // t保存着根元素

    while(j<=m){
        if(j<m && R[j].key > R[j+1].key){ //从左右孩子中找出更小的那个（默认j代表左孩子）
            j++; //若存在右子树，且右子树根的值更小，则j++后代表右子树，沿右分支筛选 (否则j代表左子树)
        }
            
        if(x < R[j].key){ //如果根的值比最小的那个孩子的值更小
            break; //筛选完毕，已经满足根小于其任一孩子值的堆（最大堆）特性，没必要再做什么事了，退出即可
        }else{ // 如果根的值比最小的那个孩子值大(暂不考虑等于的情况)
            R[i]=R[j]; //重新为根的赋值，设置为最小孩子元素值 (以保证根永远小于两个孩子的特性)
            i=j; // i保存着原来那个最小元素的位置，以便循环过后重新把原来根的值赋值给最小元素，完成交换
            j= 2*i; // j代表着新根的左孩子索引
        }
    }
    
    //上面的while只有为根重新赋最小值，但没有为原来最小元素设置新值，没有完成交换动作，所以需要在这里把原来根的值赋值到原来的最小元素位置处
    R[i] = t; // 这是假设开始根值>任一孩子的值，并交换了位置的情况下 (否则等于没交换，没变)
}