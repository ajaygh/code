function setDragDrop(a,b){a.setOption("dragEnabled",!1);var c=require("ace/lib/event");c.addListener(a.container,"dragenter",function(b){a.setReadOnly(!0)}),c.addListener(a.container,"dragleave",function(b){a.setReadOnly(!1)}),c.addListener(a.container,"dragover",function(b){a.setReadOnly(!0)}),c.addListener(a.container,"drop",function(b){a.setReadOnly(!1)})}function fixDelta(a){if(!a)return;a.start=a.start||a.range.start,a.end=a.end||a.range.end;if(a.action=="insertText"||a.action=="insertLines")a.action="insert";if(a.action=="removeText"||a.action=="removeLines")a.action="remove";return a.lines=a.lines||[a.text],a};