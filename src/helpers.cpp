//
// Created by Pieter Bouwer on 2023/09/05.
//

#include "helpers.h"

ConvertOpenCVImageToWXBitmapOutput convertOpenCVImageToWXBitmap (const ConvertOpenCVImageToWXBitmapInput& input) {
    cv::Mat image;
    input.image.copyTo(image);
    cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    cv::Size s = image.size();
    return ConvertOpenCVImageToWXBitmapOutput{
        .bitmap = wxBitmap(wxImage(s.width, s.height, image.data, TRUE), -1)
    };
}