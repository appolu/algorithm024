学习笔记
递归得方法模板即：

void Recursion(int level,int param){
	//terminator
	if(level>max_level){
		return;
	}
	//process current logic
	process(level,param);
	int tmp=level;

	//drill down
	Recursion(level,param);

	//reverse current level status if needed
	level=tmp;
}