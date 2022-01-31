/*
Desenvolvido por Hadênia Rodrigues
Exercício 1
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  cv::Mat image; 
  int x1, x2, y1, y2;

  image= cv::imread("biel.png",cv::IMREAD_GRAYSCALE);
 
  //Entra com as coordenadas dos Pontos
  cout << "Digite as coordenadas do Ponto 1: ";
  cin >> x1;
  cin >> y1;
  cout << "Digite as coordenadas do Ponto 2: ";
  cin >> x2;
  cin >> y2;

  //Adiciona o negativo na área escolhida
  for(int i=x1;i<x2;i++){
    for(int j=y1;j<y2;j++){
      image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
    }
  }
  
  //Abre a imagem, verifica se não há erro
  if(!image.data)
    std::cout << "nao abriu a imagem" << std::endl;

  cv::namedWindow("Ex1", cv::WINDOW_AUTOSIZE);
 
  cv::imshow("Ex1", image); 

  //salva imagem
  imwrite("negativo.png", image); 
  cv::waitKey();
  return 0;
}