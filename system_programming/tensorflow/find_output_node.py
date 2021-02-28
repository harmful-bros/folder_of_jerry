#!/usr/bin/env python3

import tensorflow as tf

gf = tf.compat.v1.GraphDef()
gf.ParseFromString(open('/home/jerrylee/code_test/tools/ICNet-tensorflow/model/ade20k/model.pb','rb').read()) 
#[n.name + '=>' +  n.op for n in gf.node if n.op in ( 'Softmax','Placeholder')]

for n in gf.node:
    if n.op:
        print(n.name + ' => ' + n.op)

print("Done")
