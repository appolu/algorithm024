#include <map>
//递归方法
class solution {
public:
	map<int, int> stairDic;
	int climbStairs(int n) {
		// if(n<2){
		//     return n;
		// }
		// double po1=(1+pow(5,0.5))/2.0;
		// double po2=(1-pow(5,0.5))/2.0;
		// double p5=pow(5,0.5);
		// double fin=(pow(po1,n+1)-pow(po2,n+1))/p5;
		// return fin;
		if (n == 1) return 1;
		if (n == 2) return 2;

		map<int, int>::iterator iter = stairDic.find(n);
		if (iter != stairDic.end()) {
			return iter->second;
		}
		int methods = climbStairs(n - 1) + climbStairs(n - 2);
		stairDic.insert(pair<int, int>(n, methods));
		return methods;
	}
};