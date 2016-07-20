#include <iostream>
#include <sstream>

#include <Kinect.h>

#include <opencv2\opencv.hpp>

// ERROR_CHECK(::GetDefoultKinectSensor( &kinect) );
// コードのを見やすくするためにマクロにする
// 実際には展開した形で使用する
#define ERROR_CHECK( ret )	\
	if( ( ret ) != S_OK ){	\
	std::stringstream ss;	\
	ss << "failed" #ret " " << std::hex << ret << std::endl;	\
	throw std::runtime_error( ss.str().c_str() );				\
}

void main() {
	
	try {
	
		// kinectセンサーと関連つける
		IKinectSensor* kinect = nullptr;
		ERROR_CHECK(::GetDefaultKinectSensor(&kinect));

		// kinectセンサーを起動させる
		ERROR_CHECK(kinect->Open());

		// kinectセンサーが動いたかどうかを状態を取得する
		BOOLEAN isOpen = false;
		ERROR_CHECK(kinect->get_IsOpen(&isOpen));
		std::cout << "kinect is " << (isOpen ? "Open" : "Not Open") << std::endl;

		// 少し待機
		::Sleep(3000);

		// kinectセンサーの動作を止める
		kinect->Close();
		kinect->Release();

	}

	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}