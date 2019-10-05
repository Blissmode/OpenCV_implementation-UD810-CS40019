% The goal of this project is to learn to work with images in Matlab by taking the digitized glass plate images and automatically producing a color image with as few visual artifacts as possible. In order to do this, you will need to extract the three color channel images, place them on top of each other, and align them so that they form a single RGB color image.
% The easiest way to align the parts is to exhaustively search over a window of possible displacements (You will search [-10,10] pixels), score each one using some image matching metric, and take the displacement with the best score. The simplest one is the Sum of Squared Differences (SSD) distance, which simple subtracts one image region from the other and evaluates the sum of the squared values in each pixel. You need to do SSD based calculations on image regions which are of double Opens in new tabtype.

%Read the image
img = imread('course1image.jpg');

B=img(1:341,1:400);
G=img(342:682,1:400);
R=img(683:1023,1:400);

midx = (size(G,2)/2-25)
midy = (size(G,1)/2-25)

ref_img_region = double(G(midy:midy+50,midx:midx+50))
blue_temp = double(B(midy:midy+50,midx:midx+50))
red_temp = double(R(midy:midy+50,midx:midx+50))

min = inf;

shiftr = [5,5]
shiftb = [5,5]

for x = -10 : 10
    for y = -10 : 10
        t = circshift(blue_temp,[x,y]);
        SSD = sum(sum((double(t) - double(ref_img_region)).^2));
        if( SSD < min )
            min = SSD;
            shiftb = [x,y];
        end
    end
end 

min = inf 

for x = -10 : 10
    for y = -10 : 10
        t = circshift(red_temp,[x,y]);
        SSD = sum(sum((double(t) - double(ref_img_region)).^2));
        if( SSD < min )
            min = SSD;
            shiftr = [x,y];
        end
    end
end 


shiftr=circshift(R,shiftr);
shiftb=circshift(B,shiftb);

ColorImg_aligned=cat(3,shiftr,G,shiftb)
imshow(ColorImg_aligned)
