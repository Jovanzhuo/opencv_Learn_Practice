import cv2
import numpy as np
import matplotlib.pyplot as plt

img_man = cv2.imread(r'C:\\Users\\Jovan\\Pictures\\shamo.jpg', 0)
plt.subplot(121), plt.imshow(img_man, 'gray'), plt.title('origial')
plt.xticks([]), plt.yticks([])

rows, cols = img_man.shape

mask = np.zeros(img_man.shape, np.uint8)
mask[rows/2 - 30:rows/2+30, cols/2-30:cols/2+30] = 1

f1 = np.fft.fft2(img_man)
f1shift = np.fft.fftshift(f1)
f1shift = f1shift*mask
f2shift = np.fft.ifftshift(f1shift)
img_new = np.fft.ifft2(f2shift)
img_new = np.abs(img_new)
img_new = (img_new - np.amin(img_new)) /(np.amax(img_new) - np.amin(img_new))
plt.subplot(122), plt.imshow(img_new, 'gray'), plt.title('Lowpass')
plt.xticks([]), plt.yticks([])
plt.show()