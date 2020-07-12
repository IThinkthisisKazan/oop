#include "CCircle.h"
#include <sstream>
#include <iomanip>

const std::string circle_name = "\nShape: circle";
const std::string circle_area = "\nArea: ";
const std::string circle_perimetr = "\nPerimetr: ";
const std::string circle_center = "\nCenter: ";
const std::string circle_radius = "\nRadius: ";
const std::string circle_fill_color = "\nFill color: ";
const std::string circle_outline_color = "\nOutline color: ";

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor) :
	m_center(center), m_radius(radius), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
	return 3.14 * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * 3.14 * m_radius;
}

std::string CCircle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << circle_name << circle_center << m_center.ToString() << circle_radius << m_radius << circle_area << GetArea() << circle_perimetr << GetPerimeter()
		 << circle_outline_color << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor 
		<< circle_fill_color << m_fillColor;

	return ss.str();
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}