# MCP 777

Copy assets/mcp777.xml to ${FG_ROOT}/Protocol/

Start fgfs

    fgfs --generic=socket,out,5,localhost,7770,udp,mcp777 --generic=socket,in,5,,7771,udp,mcp777
