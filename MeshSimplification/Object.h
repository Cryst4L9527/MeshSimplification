#pragma once

#include "Point.h"

class Object
{
public:
	struct Vertex;
	struct Edge;
	struct Face;

	struct ArgMatrix
	{
		double a[4][4];

		ArgMatrix& operator+=(const ArgMatrix &b)
		{
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < 4;j++) {
					a[i][j] += b.a[i][j];
				}
			}
			return *this;
		}
		ArgMatrix& operator-=(const ArgMatrix &b)
		{
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < 4;j++) {
					a[i][j] -= b.a[i][j];
				}
			}
			return *this;
		}
		void clear()
		{
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < 4;j++) {
					a[i][j] = 0;
				}
			}
		}
	};

	struct Vertex
	{
		Point p;	//����λ��
		int id;	//������
		
		std::list<Face*> faceList;
		std::list<Edge*> edgeList;

		ArgMatrix k;
		Vertex *pa;	//���鼯����

		Vertex* getroot();	//���鼯Ѱ��
		void join(Vertex *b);	//���鼯�ϲ� �Լ�����b
		Edge* findNeighborEdge(Vertex* b) const;	//�����ڵ��ұ�
		//void uniqueEdge(); //����ָ�� ȥ���ر�/��Ч��
	};

	struct Edge
	{
		Vertex *ap, *bp;

		Point pos;
		double cost;

		Vertex* findOtherVertex(const Vertex* p) const;
		bool update();	//��Ч����false
		void makeArg();
		bool ifBorderEdge() const;
	};

	struct Face
	{
		ArgMatrix k;
		Vertex *ap, *bp, *cp;

		void makeArg();
		bool update(); //��Ч����false
		void increaseNeighborPointArg();
		void decreaseNeighborPointArg();
	};

private:
	std::vector<std::unique_ptr<Vertex>> vertexPool;
	std::vector<std::unique_ptr<Edge>> edgePool;
	std::vector<std::unique_ptr<Face>> facePool;

	bool Parse(FILE * fp);
public:
	bool Load(const char *filename);

	void simpify(double factor);

	void Save(const char* filename);
};