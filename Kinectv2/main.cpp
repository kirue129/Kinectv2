#include <iostream>
#include <sstream>

#include <Kinect.h>

#include <opencv2\opencv.hpp>

// ERROR_CHECK(::GetDefoultKinectSensor( &kinect) );
// �R�[�h�̂����₷�����邽�߂Ƀ}�N���ɂ���
// ���ۂɂ͓W�J�����`�Ŏg�p����
#define ERROR_CHECK( ret )	\
	if( ( ret ) != S_OK ){	\
	std::stringstream ss;	\
	ss << "failed" #ret " " << std::hex << ret << std::endl;	\
	throw std::runtime_error( ss.str().c_str() );				\
}

void main() {
	
	try {
	
		// kinect�Z���T�[�Ɗ֘A����
		IKinectSensor* kinect = nullptr;
		ERROR_CHECK(::GetDefaultKinectSensor(&kinect));

		// kinect�Z���T�[���N��������
		ERROR_CHECK(kinect->Open());

		// kinect�Z���T�[�����������ǂ�������Ԃ��擾����
		BOOLEAN isOpen = false;
		ERROR_CHECK(kinect->get_IsOpen(&isOpen));
		std::cout << "kinect is " << (isOpen ? "Open" : "Not Open") << std::endl;

		// �����ҋ@
		::Sleep(3000);

		// kinect�Z���T�[�̓�����~�߂�
		kinect->Close();
		kinect->Release();

	}

	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}