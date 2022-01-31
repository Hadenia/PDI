#include <opencv2/opencv.hpp>
#include <cstdlib>

using namespace cv;

int main( int argc, char** argv ){
  
  int p = 1;

  while(p < 11){
    int nClusters = 8; //quant_aglomerações 
    Mat rotulos;
    int nRodadas = p; //quant_repetição do algoritmo
    Mat centros;

    if(argc!=3){
    exit(0);
    }
    
    Mat img = imread( argv[1], CV_LOAD_IMAGE_COLOR);
    Mat samples(img.rows * img.cols, 3, CV_32F);

    for( int y = 0; y < img.rows; y++ ){
      for( int x = 0; x < img.cols; x++ ){
        for( int z = 0; z < 3; z++){
          samples.at<float>(y + x*img.rows, z) = img.at<Vec3b>(y,x)[z];
      }
    }
    }
    
    kmeans(samples,
      nClusters,
      rotulos,
      TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001),
      nRodadas,
      KMEANS_RANDOM_CENTERS,
      centros );


    Mat rotulada( img.size(), img.type() );
    for( int y = 0; y < img.rows; y++ ){
      for( int x = 0; x < img.cols; x++ ){ 
      int indice = rotulos.at<int>(y + x*img.rows,0);
      rotulada.at<Vec3b>(y,x)[0] = (uchar) centros.at<float>(indice, 0);
      rotulada.at<Vec3b>(y,x)[1] = (uchar) centros.at<float>(indice, 1);
      rotulada.at<Vec3b>(y,x)[2] = (uchar) centros.at<float>(indice, 2);
    }
    }
    
    //Gerar a imagem conforte a rodada
    if (p == 1) {
			imshow("clustered image", rotulada);
			imwrite("k1.jpg", rotulada);
		}
		if (p == 2) {
			imshow("clustered image", rotulada);
			imwrite("k2.jpg", rotulada);
		}
		if (p == 3) {
			imshow("clustered image", rotulada);
			imwrite("k3.jpg", rotulada);
		}
		if (p == 4) {
			imshow("clustered image", rotulada);
			imwrite("k4.jpg", rotulada);
		}
		if (p == 5) {
			imshow("clustered image", rotulada);
			imwrite("k5.jpg", rotulada);
		}
		if (p == 6) {
			imshow("clustered image", rotulada);
			imwrite("k6.jpg", rotulada);
		}
		if (p == 7) {
			imshow("clustered image", rotulada);
			imwrite("k7.jpg", rotulada);
		}
		if (p == 8) {
			imshow("clustered image", rotulada);
			imwrite("k8.jpg", rotulada);
		}
		if (p == 9) {
			imshow("clustered image", rotulada);
			imwrite("k9.jpg", rotulada);
		}
		if (p == 10) {
			imshow("clustered image", rotulada);
			imwrite("k10.jpg", rotulada);
		}

    waitKey( 0 );

    p++;
  }


} 