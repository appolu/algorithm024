学习笔记
//快排
int random_partition(vector<int>& nums, int l, intr) {  
	int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot  
	int pivot = nums[random_pivot_index];  
	swap(nums[random_pivot_index], nums[r]);  
	int i = l - 1;  
	for (int j=l; j<r; j++) {    
		if (nums[j] < pivot) {      
			i++;      
			swap(nums[i], nums[j]);    
		}  
	}  
	int pivot_index = i + 1;  
	swap(nums[pivot_index], nums[r]);  
	return pivot_index;
}

void random_quicksort(vector<int>& nums, int l, int r) {  
	if (l < r) {   
		int pivot_index = random_partition(nums, l, r);    
		random_quicksort(nums, l, pivot_index-1);    
		random_quicksort(nums, pivot_index+1, r);  
	}
}

//归并
void mergeSort(vector<int> &nums, int left, int right){
	if(left>=right) return;
	int mid=(left+right)>>1;
	mergeSort(nums,left,mid);
	mergeSort(nums,mid+1,right);
	merge(nums,left,mid,right);
}

void merge(vector<int>& nums,int l,int m, int r){
	vector<int> tmp(r-l+1);
	int i=l,j=m+1,k=0;
	while(i<=mid && j<=r){
		tmp[k++]=nums[i]<nums[j]?nums[i]:nums[j];
	}
	while(i<=mid){
		tmp[k++]=nums[i++];
	}
	while(j<=right){
		tmp[k++]=nums[j++];
	}
	for(int i=l,k=0;i<=right;){
		nums[i++]=tmp[k++];
	}
}

//堆排序
void heapify(vector<int> & nums,int len,int i){
	int left=2*i+1,right=2*i+2;
	int largest=i;
	if(left<=len && nums[left]>nums[largest]){
		largets=left;
	}
	if(right<=len && nums[right]>nums[largest]){
		largets=right;
	}
	if(largets!=i){
		int tmp=nums[i];
		nums[i]=nums[largest];
		nums[largest]=tmp;
		heapify(nums,length,largest);
	}
}

void heapSort(vector<int> & nums){
	if(nums.size()==0) return;
	int len=nums.size();
	for(int i=len>>1-1;i>=0;i--){
		heapify(nums,length,i);
	}
	for(int i=len-1;i>=0;i--){
		int tmp=nums[0];nums[0]=nums[i];nums[i]=tmp;
		heapify(nums,i,0);
	}
	return;
}