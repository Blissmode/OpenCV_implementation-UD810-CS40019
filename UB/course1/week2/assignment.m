% Sergei Mikhailovich Prokudin-Gorskii (1863-1944) was a photographer who, between the years 1909-1915, traveled the Russian empire and took thousands of photos of everything he saw. He used an early color technology that involved recording three exposures of every scene onto a glass plate using a red, green, and blue filter. Back then, there was no way to print such photos, and they had to be displayed using a special projector.

%Read the image
img = imread('image.jpg');

%Get the size (rows and columns) of the image

[r,c] = size(img);
rr=r/3;

%Wrire code to split the image into three equal parts and store them in B, G, R channels

B = img(1:341,:);
G = img(342:682,:);
R = img(683:1023,:);

%concatenate R,G,B channels and assign the RGB image to ColorImg variable

ColorImg = cat(3,R,G,B);
imshow(ColorImg)


