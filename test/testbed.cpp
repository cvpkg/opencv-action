#include <opencv2/opencv.hpp>

int main()
{
    cv::Size size;
    size.width = 256;
    size.height = 256;
    cv::Mat src(size, CV_8UC3);
    for (int i = 0; i < size.height; i++)
    {
        for (int j = 0; j < size.width; j++)
        {
            src.ptr(i, j)[0] = i;
            src.ptr(i, j)[1] = j;
            src.ptr(i, j)[2] = (i + j) / 2;
        }
    }
    cv::imwrite("result.png", src);

    return 0;
}