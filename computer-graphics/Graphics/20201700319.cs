using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Tao.OpenGl;

//include GLM library
using GlmNet;

using System.IO;
using System.Diagnostics;

namespace Graphics
{
    class Renderer
    {
        Shader sh;

        mat4 ModelMatrix;
        mat4 ViewMatrix;
        mat4 ProjectionMatrix;
        int ShaderModelMatrixID;
        int ShaderViewMatrixID;
        int ShaderProjectionMatrixID;

        uint shape1BufferID;
        uint shape2BufferID;
        uint shape3BufferID;
        uint shape4BufferID;
        uint shape5BufferID;
        uint shape6BufferID;

        uint BaseID_P;
        uint oneID;
        uint twoID;
        uint threeID;
        uint fourID;

        public float transX = 0.0f;
        public float transY = 0.0f;
        public float transZ = 0.0f;


        const int CIRCLE_EDGES = 100;
        uint circleBufferID_one;
        uint circleBufferID_one_face;
        uint circleBufferID_two;
        uint circleBufferID_two_face;

        uint cylinderBufferID_one;
        uint cylinderBufferID_two;

        Stopwatch sw = Stopwatch.StartNew();

        vec3 triangleCenter = new vec3(10, 7, -5);

        public void Initialize()
        {
            string projectPath = Directory.GetParent(Environment.CurrentDirectory).Parent.FullName;
            sh = new Shader(projectPath + "\\Shaders\\SimpleVertexShader.vertexshader", projectPath + "\\Shaders\\SimpleFragmentShader.fragmentshader");
            Gl.glClearColor(0, 0, 0, 0);

            float[] shape1 = {
            //Back Base Side
		        0, 0, 0, 1.0f, 0.0f, 0.0f,
                2, 0, 0, 1.0f, 0.0f, 0.0f,
                2, 2, 0, 1.0f, 0.0f, 0.0f,
                0, 2, 0, 1.0f, 0.0f, 0.0f,
            };
            float[] shape2 = {
            //Bottom Face
                2, 0, 0, 0.0f, 1.0f, 0.0f,
                2, 2, 0, 0.0f, 1.0f, 0.0f,
                2, 2, 2, 0.0f, 1.0f, 0.0f,
                2, 0, 2, 0.0f, 1.0f, 0.0f,
            };
            float[] shape3 = {
            //Left Face
		        2, 0, 2, 0.8f, 0.0f, 0.8f,
                2, 2, 2, 0.8f, 0.0f, 0.8f,
                0, 2, 2, 0.8f, 0.0f, 0.8f,
                0, 0, 2, 0.8f, 0.0f, 0.8f,
            };
            float[] shape4 = {
            //Right Face
		       0, 0, 2, 0.8f, 0.8f, 0.0f,
                0, 2, 2, 0.8f, 0.8f, 0.0f,
                0, 2, 0, 0.8f, 0.8f, 0.0f,
                0, 0, 0, 0.8f, 0.8f, 0.0f,
            };
            float[] shape5 = {
            //Top Face
                 0, 0, 0, 0.2f, 0.5f, 0.6f,
               2, 0, 0, 0.2f, 0.5f, 0.6f,
               2, 0, 2, 0.2f, 0.5f, 0.6f,
               0, 0, 2, 0.2f, 0.5f, 0.6f,
            };
            float[] shape6 = {
            //Front Base Side
		         0, 2, 0, 0.8f, 0.8f, 0.8f,
                2, 2, 0, 0.8f, 0.8f, 0.8f,
                2, 2, 2, 0.8f, 0.8f, 0.8f,
                0, 2, 2, 0.8f, 0.8f, 0.8f,
            };
            float[] Base_P = {
                -0.3f, 2, -0.3f, 0, 0.2f, 0.2f,
                2.3f, 2, -0.3f, 0, 0.2f, 0.2f,
                2.3f, 2, 2.3f, 0, 0.2f, 0.2f,
                -0.3f, 2, 2.3f, 0, 0.2f, 0.2f,
            };
            float[] one = {
                -0.3f, 2, -0.3f, 0.2f, 0.2f, 0.8f,
                2.3f, 2, -0.3f, 0.2f, 0.2f, 0.8f,
                1 , 3 , 1, 0.2f, 0.2f, 0.8f,
            };
            float[] two = {
                2.3f, 2, -0.3f, 0, 0.1f, 0.4f,
                2.3f, 2, 2.3f, 0, 0.1f, 0.4f,
                1 , 3 , 1,  0, 0.1f, 0.4f,

            };
            float[] three = {
                2.3f, 2, 2.3f, 0.1f, 0.5f, 0,
               -0.3f, 2, 2.3f, 0.1f, 0.5f, 0,
                1 , 3 , 1,  0.1f, 0.5f, 0,
            };
            float[] four = {
                -0.3f, 2, -0.3f, 0.5f, 0.1f, 0,
                -0.3f, 2, 2.3f, 0.5f, 0.1f, 0,
                1 , 3 , 1, 0.5f, 0.1f, 0,
            };

            float[] circleVerts_one = draw_circle(1, 1, 0, 0.3f, 0, 1, 1);
            float[] circleVerts_one_face = draw_circle(1, 1, -1, 0.3f, 0, 1, 1);
            var cylinderPoints_one = draw_cylinder_side(1, 1, 0, 0.3f, -1);

            float[] circleVerts_two = draw_circle(1, 1, 2, 0.3f, 0, 1, 1);
            float[] circleVerts_two_face = draw_circle(1, 1, 3, 0.3f, 0, 1, 1);
            var cylinderPoints_two = draw_cylinder_side(1, 1, 2, 0.3f, 1);

            shape1BufferID = GPU.GenerateBuffer(shape1);
            shape2BufferID = GPU.GenerateBuffer(shape2);
            shape3BufferID = GPU.GenerateBuffer(shape3);
            shape4BufferID = GPU.GenerateBuffer(shape4);
            shape5BufferID = GPU.GenerateBuffer(shape5);
            shape6BufferID = GPU.GenerateBuffer(shape6);

            BaseID_P = GPU.GenerateBuffer(Base_P);
            oneID = GPU.GenerateBuffer(one);
            twoID = GPU.GenerateBuffer(two);
            threeID = GPU.GenerateBuffer(three);
            fourID = GPU.GenerateBuffer(four);


            circleBufferID_one = GPU.GenerateBuffer(circleVerts_one);
            circleBufferID_one_face = GPU.GenerateBuffer(circleVerts_one_face);
            cylinderBufferID_one = GPU.GenerateBuffer(cylinderPoints_one);

            circleBufferID_two = GPU.GenerateBuffer(circleVerts_two);
            circleBufferID_two_face = GPU.GenerateBuffer(circleVerts_two_face);
            cylinderBufferID_two = GPU.GenerateBuffer(cylinderPoints_two);


            // Model Matrix Initialization
            ModelMatrix = new mat4(1);

            // View matrix 
            ViewMatrix = glm.lookAt(
                        new vec3(4, 6, 4),
                        new vec3(3, 3, 0),
                        new vec3(0, 5, 0)
                        );

            ProjectionMatrix = glm.perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

            sh.UseShader();

            ShaderModelMatrixID = Gl.glGetUniformLocation(sh.ID, "modelMatrix");
            ShaderViewMatrixID = Gl.glGetUniformLocation(sh.ID, "viewMatrix");
            ShaderProjectionMatrixID = Gl.glGetUniformLocation(sh.ID, "projectionMatrix");


            Gl.glUniformMatrix4fv(ShaderViewMatrixID, 1, Gl.GL_FALSE, ViewMatrix.to_array());
            Gl.glUniformMatrix4fv(ShaderProjectionMatrixID, 1, Gl.GL_FALSE, ProjectionMatrix.to_array());
        }

        public void Draw()
        {
            sh.UseShader();
            Gl.glClear(Gl.GL_COLOR_BUFFER_BIT);


            //1- bind
            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, shape1BufferID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_LINE_LOOP, 0, 4);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, shape2BufferID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_QUADS, 0, 4);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, shape3BufferID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_QUADS, 0, 4);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, shape4BufferID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_QUADS, 0, 4);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, shape5BufferID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_QUADS, 0, 4);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, shape6BufferID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_QUADS, 0, 4);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, BaseID_P);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_QUADS, 0, 4);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, oneID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_TRIANGLES, 0, 3);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, twoID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_TRIANGLES, 0, 3);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, threeID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_TRIANGLES, 0, 3);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, fourID);
            //2- read possitions and colors
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            //3- Draw
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glDrawArrays(Gl.GL_TRIANGLES, 0, 3);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);



            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, circleBufferID_one);
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            Gl.glDrawArrays(Gl.GL_POLYGON, 0, CIRCLE_EDGES);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);


            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, circleBufferID_two);
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            Gl.glDrawArrays(Gl.GL_POLYGON, 0, CIRCLE_EDGES);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);


            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, circleBufferID_one_face);
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            Gl.glDrawArrays(Gl.GL_POLYGON, 0, CIRCLE_EDGES);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);


            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, circleBufferID_two_face);
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            Gl.glDrawArrays(Gl.GL_POLYGON, 0, CIRCLE_EDGES);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);


            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, cylinderBufferID_one);
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            Gl.glDrawArrays(Gl.GL_QUAD_STRIP, 0, (CIRCLE_EDGES * 2) + 2);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);


            Gl.glBindBuffer(Gl.GL_ARRAY_BUFFER, cylinderBufferID_two);
            Gl.glUniformMatrix4fv(ShaderModelMatrixID, 1, Gl.GL_FALSE, ModelMatrix.to_array());
            Gl.glEnableVertexAttribArray(0);
            Gl.glVertexAttribPointer(0, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)0);
            Gl.glEnableVertexAttribArray(1);
            Gl.glVertexAttribPointer(1, 3, Gl.GL_FLOAT, Gl.GL_FALSE, 6 * sizeof(float), (IntPtr)(3 * sizeof(float)));
            Gl.glDrawArrays(Gl.GL_QUAD_STRIP, 0, (CIRCLE_EDGES * 2) + 2);
            Gl.glDisableVertexAttribArray(0);
            Gl.glDisableVertexAttribArray(1);
        }
        const float rotationSpeed = 3f;
        float rotationAngel = 0;


        public float[] draw_circle(float centerX, float centerY, float centerZ, float radius, float R, float G, float B)
        {
            List<float> verticies = new List<float>();

            float step = (float)(2 * Math.PI) / CIRCLE_EDGES;

            float angle = 0.0f;
            while (angle < 2 * Math.PI)
            {
                float x = centerX + (float)(radius * Math.Cos(angle));
                float y = centerY + (float)(radius * Math.Sin(angle));
                verticies.AddRange(new float[] { x, y, centerZ, R, G, B });
                angle += step;
            }

            return verticies.ToArray();
        }


        public float[] draw_cylinder_side(float centerX, float centerY, float centerZ, float radius, float height)
        {
            float R = 0.6f, G = 0.2f, B = 0.4f;
            List<float> verticies = new List<float>();

            float step = (float)(2 * Math.PI) / CIRCLE_EDGES;

            float angle = 0.0f;
            while (angle < 2 * Math.PI)
            {
                float x = centerX + (float)(radius * Math.Cos(angle));
                float y = centerY + (float)(radius * Math.Sin(angle));
                verticies.AddRange(new float[] { x, y, centerZ, R, G, B });
                verticies.AddRange(new float[] { x, y, centerZ + height, R, G, B });
                angle += step;
            }
            verticies.AddRange(verticies.GetRange(0, 12));

            return verticies.ToArray();
        }


        public void Update()
        {
            sw.Stop();
            float elappsedtime = sw.ElapsedMilliseconds / 1000.0f;
            rotationAngel += rotationSpeed * elappsedtime;

            List<mat4> trans = new List<mat4>();
            trans.Add(glm.rotate(rotationAngel, new vec3(1, 0, 0)));
            trans.Add(glm.translate(new mat4(1), new vec3(transX, 0, 0)));
            trans.Add(glm.translate(new mat4(1), new vec3(0, transY, 0)));
            trans.Add(glm.translate(new mat4(1), new vec3(0, 0, transZ)));

            ModelMatrix = MathHelper.MultiplyMatrices(trans);

            sw.Restart();
            sw.Start();
        }
        public void CleanUp()
        {
            sh.DestroyShader();
        }
    }
}
