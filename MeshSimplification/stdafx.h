// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <vector>
#include <algorithm>
#include <memory>
//#include <cassert>
#include <cmath>
#include <set>
#include <tuple>
#include <functional>
#include <iostream>

const double eps = 1e-10;

inline void assert(bool x)
{
	if(!x)
		throw 1;
}