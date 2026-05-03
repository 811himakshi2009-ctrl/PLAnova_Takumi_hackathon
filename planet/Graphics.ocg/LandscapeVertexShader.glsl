/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2015, The PLAnova Team and contributors
 */

// Default Vertex Shader for the landscape.

in vec2 oc_Position;
in vec2 oc_LandscapeTexCoord;
in vec2 oc_LightTexCoord;

out vec2 landscapeTexCoord;
#ifdef OC_DYNAMIC_LIGHT
out vec2 lightTexCoord;
#endif

uniform mat4 projectionMatrix;

slice(position)
{
	// model-view matrix is always the identity matrix
	gl_Position = projectionMatrix * vec4(oc_Position, 0.0, 1.0);
}

slice(texcoord)
{
	landscapeTexCoord = oc_LandscapeTexCoord;
#ifdef OC_DYNAMIC_LIGHT
	lightTexCoord = oc_LightTexCoord;
#endif
}
