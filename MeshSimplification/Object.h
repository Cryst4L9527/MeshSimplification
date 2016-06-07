#pragma once

class Object
{
public:
	struct Vertex;
	struct Edge;
	struct Face;

	struct Vertex
	{
		union {
			struct { /*��������*/double p[3]; };
			struct { /*��������*/double x, y, z; };
		};
		int id;
		Edge* e;
	};

	struct Edge
	{
		Edge *next, *prev, *pair;
		Face* f;
		Vertex *p;
	};

	struct Face
	{
		double a, b, c, d;
		Edge* e;
		
		void makeArg(const Vertex &ap, const Vertex &bp, const Vertex &cp);
	};
private:
	std::vector<std::unique_ptr<Vertex>> vertexPool;
	std::vector<std::unique_ptr<Edge>> edgePool;
	std::vector<std::unique_ptr<Face>> facePool;

	bool Parse(FILE * fp);
	void buildStruct();
public:
	bool Load(const char *filename);


};