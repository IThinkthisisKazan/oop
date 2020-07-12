#include "CTriangle.h"
#include <sstream>
#include <iomanip>

const std::string triangle_name = "\nShape: triangle";
const std::string triangle_area = "\nArea: ";
const std::string triangle_perimetr = "\nPerimetr: ";
const std::string triangle_vertex1 = "\nVertex1: ";
const std::string triangle_vertex2 = "\nVertex2: ";
const std::string triangle_vertex3 = "\nVertex3: ";
const std::string triangle_fill_color = "\nFill color: ";
const std::string triangle_outline_color = "\nOutline color: ";

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor) :
	m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CTriangle::GetArea() const
{
	return abs(((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y))
		- ((m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y))) / 2;
}

double CTriangle::GetPerimeter() const
{
	double l12 = sqrt(pow(m_vertex1.x - m_vertex2.x, 2) + pow(m_vertex1.y - m_vertex2.y, 2));
	double l23 = sqrt(pow(m_vertex2.x - m_vertex3.x, 2) + pow(m_vertex2.y - m_vertex3.y, 2));
	double l31 = sqrt(pow(m_vertex3.x - m_vertex1.x, 2) + pow(m_vertex3.y - m_vertex1.y, 2));
	return l12 + l23 + l31;
}

std::string CTriangle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss.precision(2);
	ss << triangle_name << triangle_vertex1 << m_vertex1.ToString()<< triangle_vertex2 << m_vertex2.ToString()<< triangle_vertex3 << m_vertex3.ToString()
		<< triangle_area << GetArea()<< triangle_perimetr << GetPerimeter()
		<< triangle_outline_color << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor
		<< triangle_fill_color << m_fillColor;
	return ss.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}