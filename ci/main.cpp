# include <iostream>
#include <Eigen/Dense>

using namespace std;
int main()
{
    cout << "This is test file for Eigen ";

    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
	system("PAUSE");
    return 0;
}
