#pragma once
#ifndef VOXEL_CHUNK_H
#define VOXEL_CHUNK_H

#define CHUNK_W 16
#define CHUNK_H 16
#define CHUNK_D 16
#define CHUNK_VOL (CHUNK_W * CHUNK_H * CHUNK_D)

class voxel;

class Chunk
{
public:
	voxel* voxels;
	Chunk();
	~Chunk();
};

#endif // !VOXEL_CHUNK_H
