#pragma once
#include <cstdint>


struct TraceHeader { // 64 bytes
  uint8_t magic[4] = {'H', 'L', 'T', 'R'};
  uint8_t version[4] = {0, 0, 0, 0};
  uint64_t reserved[8] = {0, 0, 0, 0, 0, 0, 0, 0};
};

enum BlockType : uint8_t { default, function_call, frame_marker, data_block, function_return };

struct BlockHeader {
  uint64_t size;
  BlockType type;
  uint8_t reserved1;
  uint8_t reserved2;
  uint8_t reserved3;
  uint16_t api_id;
  uint16_t call_id;
};

struct FunctionCall : BlockHeader {
};

struct FunctionReturn : BlockHeader  {
};

struct FrameMarker : BlockHeader {
  uint64_t frame_id;
};

struct DataBlock : BlockHeader {
};

