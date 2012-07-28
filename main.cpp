#include <QImage>

int makeGradientImage()
{
    QImage image(720, 960, QImage::Format_RGB888);

    for (int h = 0; h < image.height(); h++) {
        for (int w = 0; w < image.width(); w++) {
            image.setPixel(w, h, qRgb(h * 255.0 / (image.height() - 1),
                                      h * 255.0 / (image.height() - 1),
                                      h * 255.0 / (image.height() - 1)));
        }
    }
    image.save("gradient.png");
}

int makeLookupImage()
{
    QImage image(512, 512, QImage::Format_RGB888);

    // TODO: There is a small aliasing problem.
    for (int by = 0; by < 8; by++) {
        for (int bx = 0; bx < 8; bx++) {
            for (int g = 0; g < 64; g++) {
                for (int r = 0; r < 64; r++) {
                    image.setPixel(r + bx * 64, g + by * 64, qRgb((int)(r * 255.0 / 63.0 + 0.5),
                                                                  (int)(g * 255.0 / 63.0 + 0.5),
                                                                  (int)((bx + by * 8.0) * 255.0 / 63.0 + 0.5)));
                }
            }
        }
    }
    image.save("lookup.png");
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);
    makeGradientImage();
    makeLookupImage();

    return 0;
}
