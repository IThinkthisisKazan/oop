#include "CRectangle.h"
#include <sstream>
#include <iomanip>

const std::string rectangle_name = "\nShape: rectangle";
const std::string rectangle_area = "\nArea: ";
const std::string rectangle_perimetr = "\nPerimetr: ";
const std::string rectangle_left_top = "\nLeft top: ";
const std::string rectangle_height = "\nHeight: ";
const std::string rectangle_width = "\nWidth: ";
const std::string rectangle_fill_color = "\nFill color: ";
const std::string rectangle_outline_color = "\nOutline color: ";

CRectangle::CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor) :
	m_leftTop(leftTop), m_width(width), m_height(height), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << rectangle_name << rectangle_left_top << m_leftTop.ToString() << rectangle_width << m_width << rectangle_height << m_height << rectangle_area << GetArea()
		<< rectangle_perimetr << GetPerimeter()<< rectangle_outline_color << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor
		<< rectangle_fill_color << m_fillColor;

	return ss.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return { m_leftTop.x + m_width, m_leftTop.y - m_height };
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}