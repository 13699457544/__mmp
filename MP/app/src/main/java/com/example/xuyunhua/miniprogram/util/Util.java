package com.example.xuyunhua.miniprogram.util;

import android.content.Context;
import android.content.res.AssetManager;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Util {

   public static String __read__(String name, Context context){
      AssetManager am = context.getAssets();
       try {
           InputStream in = am.open(name,3);
           InputStreamReader in_read = new InputStreamReader(in);
           BufferedReader reader = new BufferedReader(in_read);
           StringBuffer s_b_ = new StringBuffer();
           String line ="";
           while ((line=reader.readLine())!=null){
               s_b_.append(line);
           }
           return s_b_.toString();
       } catch (IOException e) {
           e.printStackTrace();
       }
       return "";
   }

   public static String __read__(String file,Context context,String name){
       return "";
   }
}
