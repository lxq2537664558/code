///  Texturesets are used to load texture-stacks asynchronously
///

///// GENERAL:
///
/// Inexors routine of loading and storing ingame-textures depends on 3 structures:
/// VSlot       - A Structure holding general info about scale, shadersettings, rotation, ..
/// Slot        - Basicly thats a "Texture" as you would find it ingame in the texturebrowser.
///               It consists of minimum 1 image (the diffuse-file) and various others providing special info (height,..).
///               Every Slot has a VSlot. (and vice versa: every VSlot has at least one Slot)
/// textureset  - A Set of textures/Slots to make loading easier and asynchronous.
///
/// The currently visible stack of ingame-textures (Slots) is vector<Slot *> slots.

#ifndef TEXTURESET_H
#define TEXTURESET_H

namespace inexor {
    namespace textureset {
        /// A set of Slots to make threaded loading possible. 
        class textureset
        {
        private:

            /// One entry to the set.
            class texentry
            {
            public:
                /// A bitmask containing which of the 8 textures of the slot already have been loaded.
                int loadmask = 0;

                /// A bitmask containing which of the 8 textures of the slot have been loaded in a thread and need a registration now.
                int needregister = 0;

                /// Whether this Slot is usable ingame.
                bool mounted = false;

                /// The Texture-Slot
                Slot *tex;

                texentry(Slot *s)
                {
                    tex = s;
                }
            };

        public:
            /// All included Slots.
            vector<texentry *>texs;

            /// Adds a texture to the set from a JSON (Object).
            void addtexture(JSON *j);

            /// Adds a texture to the set from a json-file.
            void addtexture(const char *filename);

            /// Checks if textures may do not need to be loaded since they are already stored somewhere
            void checkload();

            /// Loads all textures to memory.
            /// This function is threadsafe.
            /// @usage 1. checkload (not threaded) 2. load (threaded) 3. registerload (not threaded)
            void load();

            /// Saves loaded textures to the texture registry.
            void registerload();

            /// Add this textureset to the current texture stack of ingame visible textures.
            /// @param initial if true this textureset becomes the first and only one.
            void mount(bool initial);

            /// Mounts remaining textures.
            /// You need to use this after adding textures to a mounted set.
            void mountremaining();

            /// Removes this textureset from the current stack of ingame visible textures.
            /// Attention: all following slots will be change its position and hence this has an visual impact ingame! TODO!!
            void unmount();

            void echoall()
            {
                loopv(texs) {
                    loopvk(texs[i]->tex->sts)  conoutf("tex %d.%d: %s", i, k, texs[i]->tex->sts[k].name);
                }
            }
        };

        extern textureset *newtextureset(JSON *parent);
        extern bool loadset(const char *name);

    } // namespace textureset
}     // namespace inexor

#endif //TEXTURESET_H