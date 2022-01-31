/*
Desenvolvido por Hadênia Rodrigues
Exercício 2
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  cv::Mat image, image2; 
  cv::Mat aux1, aux2, h, w;

  image= cv::imread("hadenia.png",cv::IMREAD_GRAYSCALE);    

   //Abre a imagem, verifica se não há erro
  if(!image.data)
    std::cout << "nao abriu a imagem" << std::endl;

  cv::namedWindow("original.png", cv::WINDOW_AUTOSIZE); 
  cv::imshow("original.png", image); 

  //Salvando quadrantes
  //Rect_ (x, y, width, height)
  Mat Q1(image, Rect(0,0,(image.size().width/2),(image.size().height/2)));
  Mat Q2(image, Rect((image.size().height/2),0,(image.size().width/2),(image.size().height/2)));
  Mat Q3(image, Rect(0,(image.size().height/2),(image.size().width/2),(image.size().height/2)));
  Mat Q4(image, Rect((image.size().height/2),(image.size().height/2),(image.size().width/2),(image.size().height/2)));

  //Concatenando os quadrantes na horizontal
  hconcat(Q4, Q3, aux1);
  hconcat(Q2, Q1, aux2);
  //Concatenando os quadrantes na vertical
  vconcat(aux1, aux2, image2);
 
 //Abre a imagem, verifica se não há erro
  if(!image.data)
    std::cout << "nao abriu a imagem" << std::endl;

  cv::namedWindow("Ex2", cv::WINDOW_AUTOSIZE); 
  cv::imshow("Ex2", image2); 

  //salva imagem
  imwrite("Ex2.png", image2); 
  cv::waitKey();
  return 0;
}