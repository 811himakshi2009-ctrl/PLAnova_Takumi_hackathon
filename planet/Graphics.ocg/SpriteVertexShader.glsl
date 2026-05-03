/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2015, The PLAnova Team and contributors
 */

// Default Vertex Shader for objects and sprites.

uniform mat4 projectionMatrix;
uniform mat4 modelviewMatrix;

in vec2 oc_Position;
in vec4 oc_Color;

#ifdef OC_HAVE_BASE
in vec2 oc_TexCoord;
#endif

out vec4 vtxColor;

#ifdef OC_HAVE_BASE
out vec2 texcoord;
#endif

slice(position)
{
	// model-view matrix is always the identity matrix
	gl_Position = projectionMatrix * modelviewMatrix * vec4(oc_Position, 0.0, 1.0);
}

slice(texcoord)
{
#ifdef OC_HAVE_BASE
	texcoord = oc_TexCoord;
#endif
}

slice(color)
{
	vtxColor = oc_Color;
}
