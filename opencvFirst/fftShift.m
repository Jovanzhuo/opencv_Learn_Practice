I = imread('E:/Programma Study/VS Projects/opencvFirst/resource/timg.jpg');
I = rgb2gray(I);
F = fft2(im2double(I));
F = fftshift(F);
F = real(F);
T = log(F + 1);
subplot(1, 2, 1),imshow(I),title('raw');
subplot(1, 2, 2),imshow(T,[]),title('freqZoom');