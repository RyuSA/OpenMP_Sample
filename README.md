# OpenMP_Sampleの使い方
自主ゼミ用

## ソースファイルの場所
OpenMP_Sample / Souce.cpp
が目的ファイル
Visual Studioのプロジェクトプロパティから、C/C++ > 言語 > OpenMPの有効化 にチェックを加えること

## 関数について
printMatrix : Matrixをいい感じに表示してくれる

GenerateMatrix : Matrixを要素ランダムにして生成する

Standard_mult(Z,X,Y) : Z = XYを計算する。高速化はしていない。

## 例
// Matrix Xを生成(乱数で初期化)

auto X = GenerateMatrix();


// Matrix Yを生成(乱数で初期化)

auto Y = GenerateMatrix();


// Matrix Zを生成

Matrix Z(Degree);


// Xを表示

printMatrix(X)


// Z = XYを実行

Standard_mult(X,Y,Y);
