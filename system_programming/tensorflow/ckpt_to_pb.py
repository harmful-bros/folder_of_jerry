#!/usr/bin/env python3

import tensorflow as tf

BASE_PATH="/home/jerrylee/code_test/tools/ICNet-tensorflow/model/ade20k"

#First let's load meta graph and restore weights
with tf.compat.v1.Session() as sess:

    # load ckpt file
    saver = tf.compat.v1.train.import_meta_graph(BASE_PATH + '/model.ckpt-27150.meta')
    saver.restore(sess,tf.train.latest_checkpoint(BASE_PATH))

    output_node_names = [n.name for n in tf.compat.v1.get_default_graph().as_graph_def().node]
#    print(output_node_names)

    # create the pb & pbtxt file
    tf.io.write_graph(sess.graph_def, BASE_PATH, "model.pb", as_text=False)        
    tf.io.write_graph(sess.graph_def, BASE_PATH, "model.pbtxt", as_text=True)

    # freeze
    frozen_graph_def = tf.graph_util.convert_variables_to_constants(sess, sess.graph_def, output_node_names)

    # Save the frozen graph
    with open(BASE_PATH + '/ade20k.pb', 'wb') as f:
        f.write(frozen_graph_def.SerializeToString())

print("Done")


#import os
#import tensorflow as tf
#
#trained_checkpoint_prefix = 'model/ade20k/model.ckpt-27150'
#export_dir = os.path.join('output', '0') # IMPORTANT: each model folder must be named '0', '1', ... Otherwise it will fail!
#
#loaded_graph = tf.Graph()
#with tf.Session(graph=loaded_graph) as sess:
#    # Restore from checkpoint
#    loader = tf.train.import_meta_graph(trained_checkpoint_prefix + '.meta')
#    loader.restore(sess, trained_checkpoint_prefix)
#
#    # Export checkpoint to SavedModel
#    builder = tf.saved_model.builder.SavedModelBuilder(export_dir)
#    builder.add_meta_graph_and_variables(sess,
#                                         [tf.saved_model.tag_constants.TRAINING, tf.saved_model.tag_constants.SERVING],
#                                         strip_default_attrs=True)
#    builder.save()
