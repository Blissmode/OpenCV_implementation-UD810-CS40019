% The image gradient magnitude corresponds to the strength of edges in any given image. 
% In this problem, you will evaluate the Sobel Image Gradients Gx and Gy for the 'cameraman.tif' image and subsequently Gradient magnitude Gmag and Gradient direction Gdir


img=imread('cameraman.tif');
[Gx,Gy]=imgradientxy(img,'sobel');

%Uncomment the code below to visualize Gx and Gy

imshowpair(Gx,Gy,'montage')
[Gmag,Gdir] = imgradient(img,'sobel')

%Uncomment the code below to visualize Gmag and Gdir
imshowpair(Gmag,Gdir,'montage')

