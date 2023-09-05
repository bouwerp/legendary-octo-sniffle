//
// Created by Pieter Bouwer on 2023/09/05.
//

#ifndef LEGENDARY_OCTO_SNIFFLE_HELPERS_H
#define LEGENDARY_OCTO_SNIFFLE_HELPERS_H

#include <wx/wxprec.h>
#include <wx/setup.h>
#include <wx/mstream.h>

#include <opencv2/opencv.hpp>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

struct ConvertOpenCVImageToWXBitmapInput {
    cv::Mat image;
};
struct ConvertOpenCVImageToWXBitmapOutput {
    wxBitmap bitmap;
};
/**
 * A helper function that does converts a given OpenCV image to a wxWidgets wxBitmap.
 * @return
 */
ConvertOpenCVImageToWXBitmapOutput convertOpenCVImageToWXBitmap (const ConvertOpenCVImageToWXBitmapInput&);

#endif //LEGENDARY_OCTO_SNIFFLE_HELPERS_H
